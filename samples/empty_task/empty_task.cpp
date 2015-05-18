//********************************************************************************
// Copyright (c) 2007-2014 Intel Corporation. All rights reserved.              **
//                                                                              **
// Redistribution and use in source and binary forms, with or without           **
// modification, are permitted provided that the following conditions are met:  **
//   * Redistributions of source code must retain the above copyright notice,   **
//     this list of conditions and the following disclaimer.                    **
//   * Redistributions in binary form must reproduce the above copyright        **
//     notice, this list of conditions and the following disclaimer in the      **
//     documentation and/or other materials provided with the distribution.     **
//   * Neither the name of Intel Corporation nor the names of its contributors  **
//     may be used to endorse or promote products derived from this software    **
//     without specific prior written permission.                               **
//                                                                              **
// This software is provided by the copyright holders and contributors "as is"  **
// and any express or implied warranties, including, but not limited to, the    **
// implied warranties of merchantability and fitness for a particular purpose   **
// are disclaimed. In no event shall the copyright owner or contributors be     **
// liable for any direct, indirect, incidental, special, exemplary, or          **
// consequential damages (including, but not limited to, procurement of         **
// substitute goods or services; loss of use, data, or profits; or business     **
// interruption) however caused and on any theory of liability, whether in      **
// contract, strict liability, or tort (including negligence or otherwise)      **
// arising in any way out of the use of this software, even if advised of       **
// the possibility of such damage.                                              **
//********************************************************************************

// compute fibonacci numbers
//

#define _CRT_SECURE_NO_DEPRECATE // to keep the VS compiler happy with TBB

#include "empty_task.h"
#include <chrono>

int empty_step::execute(const int &tag, empty_context &context) const
{
    return CnC::CNC_Success;
}

int main()
{
	const int n = 10000000;

    CnC::debug::set_num_threads(4);

    // create context
    empty_context context;

	auto start = std::chrono::high_resolution_clock::now();

    // put tags to initiate evaluation
    for (int i = 0; i <= n; ++i) 
		context.tags.put( i );

    // wait for completion
    context.wait(); 

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " sec" << std::endl;

    return 0;
}
