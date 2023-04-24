#include "SendEmail_Library.hh"

auto SendEmail_Library::SendEmail(std::string smtp,
								std::string FromName,
								std::string FromEmail,
								std::string Password,
								std::string ToName,
								std::string ToEmail,
								std::string Subject,
								std::string Message) -> int
{

    try
    {

        mailio::message msg;
        msg.header_codec(mailio::message::header_codec_t::BASE64);
        msg.from(mailio::mail_address(FromName, FromEmail));
        msg.add_recipient(mailio::mail_address(ToName, ToEmail));

        msg.subject(Subject);
        msg.content_transfer_encoding(mailio::mime::content_transfer_encoding_t::QUOTED_PRINTABLE);
        msg.content_type(mailio::message::media_type_t::TEXT, "plain", "utf-8");

        msg.content(convertToUTF8(Message));

        mailio::smtps conn(smtp, 587);
        conn.authenticate(FromEmail, Password, mailio::smtps::auth_method_t::START_TLS);
        conn.submit(msg);

    }
    catch (mailio::smtp_error& exc)
    {

        return EXIT_FAILURE;

    }
    catch (mailio::dialog_error& exc)
    {
        
        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

}

auto SendEmail_Library::convertToUTF8(const std::string& input)->std::string
{

    int size = MultiByteToWideChar(CP_ACP, 0, input.c_str(), -1, nullptr, 0);
    std::wstring wstr(size, 0);
    MultiByteToWideChar(CP_ACP, 0, input.c_str(), -1, &wstr[0], size);

    size = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string output(size, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &output[0], size, nullptr, nullptr);

    return output;

}