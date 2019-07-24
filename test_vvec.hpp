#pragma once

void TEST__vvec__Tr_00(){
	std::vector<std::vector<int>> vvec = {
		{ 1,  2,  3,  4}, 
		{ 5,  6}, 
		{ 7,  8,  9, 10, 11, 12, 13, 14}, 
		{15, 16, 17}, 
		{18, 19}, 
		{20, 21, 22, 23}, 
		{24, 25}, 
		{26, 27, 28}, 
		{29}
	};
	std::vector<std::vector<int>> vvecTr = sstd::Tr<int>(vvec);
	sstd::printn(vvecTr);
	
	std::vector<std::vector<int>> vvecAns = {
		{ 1,  5,  7, 15, 18, 20, 24, 26, 29},
		{ 2,  6,  8, 16, 19, 21, 25, 27}, 
		{ 3,  0,  9, 17,  0, 22,  0, 28},
		{ 4,  0, 10,  0,  0, 23},
		{ 0,  0, 11},
		{ 0,  0, 12},
		{ 0,  0, 13},
		{ 0,  0, 14}
	};
	
	ASSERT_TRUE(vvecTr == vvecAns);
	ASSERT_TRUE((int)123 == (int)123);
}

//------------------------------------------

// 後は間違えそうなテストをいっぱい書いてみて，通れば良しとしよう．


TEST(vvec, Tr_00){ TEST__vvec__Tr_00(); }

