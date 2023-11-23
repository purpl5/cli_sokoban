/*
*  Dans le cas ou :
*     - Windows : OS_NUMBER 0
*     - Unix : (linux, Mac OS..) OS_NUMBER 1 
*/

#ifdef _WIN32
#define OS_NUMBER 0
#endif

#ifdef __APPLE__
#define OS_NUMBER 1
#endif

#ifdef __unix__
#define OS_NUMBER 1
#endif