#pragma once
#include <mailio/message.hpp>
#include <mailio/mime.hpp>
#include <mailio/smtp.hpp>

class SendEmail_Library
{

public:
    auto SendEmail(std::string smtp,
        std::string FromName,
        std::string FromEmail,
        std::string Password,
        std::string ToName,
        std::string ToEmail,
        std::string Subject,
        std::string Message) -> int;


private:
	auto convertToUTF8(const std::string& input) -> std::string;

};

