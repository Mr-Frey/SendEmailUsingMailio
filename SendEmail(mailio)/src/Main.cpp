#include <iostream>
#include "Library's/SendEmail.hh"

auto main() -> int {

    return SendEmail("smtp-mail.outlook.com",
        "Frey",
        "Frey@outlook.com.br",
        "Frey1234Password",
        "Cleber",
        "Cleber@outlook.com.br",
        "Test Message",
        "Here I write the text I want to send to the person.");

}