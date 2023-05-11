#include <iostream>
#include <map>
#include <string>

int main(int argc, char **argv)
{
    std::map<std::string, std::string> users = {
        {"Anny", "password123"},
        {"Eve", "qwerty"},
        {"Bob", "aezakmi"},
        {"Jack", "mysecurepassword"},
        {"Joshua", "123123"}    
    };
    
    std::cout << "Users with password length > 6: " << std::endl;
    for (auto& user: users)
    {
        if (user.second.size() > 6)
        {
            std::cout << "Username: " << user.first;
            std::cout << " Password: " << user.second;
            std::cout << "\n"; 
        }
    }

    return 0;
}