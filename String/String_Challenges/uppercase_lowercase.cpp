#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// int main()
// {
//     string str = "nndfnemkdjsfmsfn";

//     //  convert into uppercase

//     for (int i = 0; i < str.size(); i++)
//     {
//         if (str[i] >= 'a' && str[i] <= 'z')
//         {
//             str[i] -= 32;
//         }
//     }
//     cout << str << endl;

//     //  convert to lowercase

//     for (int i = 0; i < str.size(); i++)
//     {
//         if (str[i] >= 'A' && str[i] <= 'Z')
//         {
//             str[i] += 32;
//         }
//     }
//     cout << str << endl;

//     return 0;
// }

int main()
{
    string s = "fghfsjflfsjfsjfs";

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;

    return 0;
}