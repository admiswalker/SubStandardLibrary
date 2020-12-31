#pragma once

//-----------------------------------------------------------------------------------------------------------------------------------------------
// 

TEST(strmatch, strmatch){
    const char* str = "abcdefghijk";
    const char* WildCard1 = "abc*";
    const char* WildCard2 = "a?cdefghijk";
    const char* WildCard3 = "a?";

    // strmatch
      // test (1)
    ASSERT_TRUE ( sstd::strmatch(str, WildCard1) );
    ASSERT_TRUE ( sstd::strmatch(str, WildCard2) );
    ASSERT_FALSE( sstd::strmatch(str, WildCard3) );
      // test (2)
    ASSERT_TRUE( sstd::strmatch("TOKYOTO...", "??KYOTO*") );
    
    std::string ret;
    ASSERT_TRUE( sstd::strmatch_getWC("TOKYOTO...", "TO*...", ret) );
    ASSERT_STREQ(ret.c_str(), "KYOTO"); ASSERT_EQ(ret.size(), (uint)5);
    
    ASSERT_TRUE( sstd::strmatch_getWC("TOKYOTO...", "??KYOTO*", ret) );
    ASSERT_STREQ(ret.c_str(), "TO..."); ASSERT_EQ(ret.size(), (uint)5);
    
    ASSERT_TRUE( sstd::strmatch_getWC("TOKYOTO...", "*KYOTO.*.", ret) );
    ASSERT_STREQ(ret.c_str(), "TO."); ASSERT_EQ(ret.size(), (uint)3);
    
    ASSERT_TRUE( sstd::strmatch_getWC("TOKYOTO...", "TO?????.*.", ret) );
    ASSERT_STREQ(ret.c_str(), "KYOTO."); ASSERT_EQ(ret.size(), (uint)6);
    
    ASSERT_TRUE( sstd::strmatch_getWC("TOKYOTO...", "T*?T?*...*", ret) );
    ASSERT_STREQ(ret.c_str(), "OKYOO"); ASSERT_EQ(ret.size(), (uint)5);
    
    // strmatch_getWC
    std::string retWC;
    ASSERT_TRUE ( sstd::strmatch_getWC(str, WildCard1, retWC) ); ASSERT_STREQ(retWC.c_str(), "defghijk"); ASSERT_TRUE( retWC.size()==8 ); retWC.clear();
    ASSERT_TRUE ( sstd::strmatch_getWC(str, WildCard2, retWC) ); ASSERT_STREQ(retWC.c_str(), "b"       ); ASSERT_TRUE( retWC.size()==1 ); retWC.clear();
    ASSERT_FALSE( sstd::strmatch_getWC(str, WildCard3, retWC) ); ASSERT_STREQ(retWC.c_str(), ""        ); ASSERT_TRUE( retWC.size()==0 );
    
    // isNum
    ASSERT_TRUE ( sstd::isNum('0') );
    ASSERT_TRUE ( sstd::isNum('5') );
    ASSERT_TRUE ( sstd::isNum('9') );
    ASSERT_FALSE( sstd::isNum('a') );
    ASSERT_FALSE( sstd::isNum('A') );
    
    // isAlphabet
    ASSERT_TRUE ( sstd::isAlphabet('a') );
    ASSERT_TRUE ( sstd::isAlphabet('A') );
    ASSERT_FALSE( sstd::isAlphabet('0') );
    ASSERT_FALSE( sstd::isAlphabet('9') );
    
    ASSERT_TRUE ( sstd::isAlphabet_onlyUpper('A') );
    ASSERT_FALSE( sstd::isAlphabet_onlyUpper('a') );
    
    ASSERT_TRUE ( sstd::isAlphabet_onlyLower('a') );
    ASSERT_FALSE( sstd::isAlphabet_onlyLower('A') );
}





