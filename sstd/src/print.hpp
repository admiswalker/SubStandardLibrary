﻿#pragma once
#include <string>
#include <vector>
#include "./typeDef.h"


namespace sstd{
    // woLF: without line feed code ('\n')
    void print_woLF(const  bool  rhs);
    void print_woLF(const  char  rhs);
    void print_woLF(const  int8  rhs);
    void print_woLF(const  int16 rhs);
    void print_woLF(const  int32 rhs);
    void print_woLF(const  int64 rhs);
    void print_woLF(const uint8  rhs);
    void print_woLF(const uint16 rhs);
    void print_woLF(const uint32 rhs);
    void print_woLF(const uint64 rhs);
    void print_woLF(const float  rhs);
    void print_woLF(const double  rhs); // Note: Prioritize readability and do not display all effective digits of double-precision type.
    void print_woLF(const        char* rhs);
    void print_woLF(const std::string& rhs);
    template <typename T>
    void print_woLF(const std::vector<T>& rhs){
        printf("[");
        if(rhs.size()>=1){
            for(uint i=0; i<rhs.size()-1; ++i){ sstd::print_woLF(rhs[i]); printf(" "); }
            sstd::print_woLF( rhs[rhs.size()-1] );
        }
        printf("]");
    }
    
    // with line feed code ('\n')
    void print(const  bool  rhs);
    void print(const  char  rhs);
    void print(const  int8  rhs);
    void print(const  int16 rhs);
    void print(const  int32 rhs);
    void print(const  int64 rhs);
    void print(const uint8  rhs);
    void print(const uint16 rhs);
    void print(const uint32 rhs);
    void print(const uint64 rhs);
    void print(const float  rhs);
    void print(const double rhs);
    void print(const        char* rhs);
    void print(const std::string& rhs);
    template <typename T>
    void print(const std::vector<T>& rhs){ sstd::print_woLF(rhs); printf("\n"); }
    
    void for_printn( bool  rhs);
    void for_printn( char  rhs);
    void for_printn( int8  rhs);
    void for_printn( int16 rhs);
    void for_printn( int32 rhs);
    void for_printn( int64 rhs);
    void for_printn(uint8  rhs);
    void for_printn(uint16 rhs);
    void for_printn(uint32 rhs);
    void for_printn(uint64 rhs);
    void for_printn( float rhs);
    void for_printn(double rhs);
    void for_printn(const        char* rhs);
    void for_printn(const std::string& rhs);
    template <typename T>
    void for_printn(const std::vector<T>& rhs){
        printf(" = ");
        sstd::print_woLF(rhs); // using "without line feed" version for recursive call for deep std::vector<std::vector<... std::vector<T>... >>.
        printf("\n");
    }

    //---
    
    // for #define
    inline void printn_dummy(){}
    inline void printn(...){}
    inline void printn_all(...){}
}

#define printn(var) printn_dummy();{printf("%s", #var);sstd::for_printn(var);}
#define printn_all(var) printn_dummy();{printf("%s(%d): %s", __func__, __LINE__, #var);sstd::for_printn(var);}
#define printn_fflv(var) printn_dummy();{printf("%s: %s(%d): %s", __FILE__, __func__, __LINE__, #var);sstd::for_printn(var);}

