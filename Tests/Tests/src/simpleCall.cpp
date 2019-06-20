 #include "../../Catch/catch.hpp"
 #include <stdlib.h>
 
 #include "commandline.cpp"
 
 using namespace std;
 
 extern commandline COM;
 
TEST_CASE( "MutComp correctly installed", "" )
{
    //string s = exec("./Tests/./test.sh");
    
    COM.makeCall("process");
    
    REQUIRE(COM.getStatus() == 1);
    REQUIRE(COM.valContains("Input folder not found"));
        
}
