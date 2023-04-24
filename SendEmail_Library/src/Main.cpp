#include <iostream>
#include "SendEmail_Library.hh"

auto main() -> int
{

    SendEmail_Library* sendEmail = new SendEmail_Library();

    int Result = sendEmail->SendEmail("smtp-mail.outlook.com",
        "Frey",
        "Frey@outlook.com.br",
        "Frey1234Password",
        "Cleber",
        "Cleber@outlook.com.br",
        "Test Message",
        "Here I write the text I want to send to the person.");

    if (Result != 0)
    {

        std::cout << "Falha ao enviar email!" << std::endl;

        return 0;

    }
    else
    {

        std::cout << "Sucesso ao enviar email!" << std::endl;

        return 0;

    }

}