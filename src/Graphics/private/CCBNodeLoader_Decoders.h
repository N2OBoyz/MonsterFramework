//----------------------------------------------------------------------------//
//                 █      █                                                   //
//                 ████████                                                   //
//               ██        ██                                                 //
//              ███  █  █  ███    CCBNode_Loader_Decoders.h                   //
//              █ █        █ █    MonsterFramework                            //
//               ████████████                                                 //
//             █              █   Copyright (c) 2015 AmazingCow               //
//            █     █    █     █  www.AmazingCow.com                          //
//            █     █    █     █                                              //
//             █              █   N2OMatt - n2omatt@amazingcow.com            //
//               ████████████     www.amazingcow.com/n2omatt                  //
//                                                                            //
//                                                                            //
//                  This software is licensed as BSD-3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgmentopensource@AmazingCow.com               //
//     3. Altered source versions must be plainly marked as such,             //
//        and must notbe misrepresented as being the original software.       //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

#ifndef __MonsterFramework_src_Graphics_private_CCBNodeLoader_Decoders_h__
#define __MonsterFramework_src_Graphics_private_CCBNodeLoader_Decoders_h__

//MonsterFramework
#include "MonsterFramework/include/Utils/MonsterFramework_Utils.h"

NS_MF_BEGIN

//Decoders.
cc::Point   _decodeAsPoint       (const cc::Value &value);
bool        _decodeAsCheck       (const cc::Value &value);
cc::Point   _decodeAsPosition    (const cc::Value &value, cc::Node *pNode);
std::string _decodeAsSpriteFrame (const cc::Value &value);
std::string _decodeAsBlock       (const cc::Value &value);
cc::Color3B _decodeAsColor3      (const cc::Value &value);
cc::Size    _decodeAsSize        (const cc::Value &value, cc::Node *pNode);
float       _decodeAsDegrees     (const cc::Value &value);
float       _decodeAsFontScale   (const cc::Value &value);
std::string _decodeAsString      (const cc::Value &value);
int         _decodeAsByte        (const cc::Value &value);

NS_MF_END
#endif // defined(__MonsterFramework_src_Graphics_private_CCBNodeLoader_Decoders_h__) //
