// Q: How do I enumerate files and sub-directories
//    using C++?

// Q: How do I enable compiler support for
//    the C++17 standard in Visual Studio?


#include <iostream>
using std::cout;
using std::endl;

// You may need to manually enable compiler support
// for the C++17 standard when using certain
// functionality like std::filesystem. To do this in
// Visual Studio, add "/std:c++17" to the compiler 
// command line parameters
#include <filesystem>
using std::filesystem::current_path;
using std::filesystem::path;
using std::filesystem::directory_entry;
using std::filesystem::recursive_directory_iterator;

int main()
{
    // Get current working directory
    const path p{ current_path() };

    // Recursively enumerate files and sub-directories
    for (const directory_entry dir_entry : recursive_directory_iterator{ p })
    {
        // Print the file or directory path
        cout << dir_entry.path();

        // Is it a directory? Is it a file?
        if (dir_entry.is_directory())
            cout << " (a directory)" << endl;
        else if (dir_entry.is_regular_file())
            cout << " (a file)" << endl;
    }

    return 0;
}