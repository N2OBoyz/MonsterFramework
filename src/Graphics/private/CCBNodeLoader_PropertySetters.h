﻿//----------------------------------------------------------------------------//
//                 █      █                                                   //
//                 ████████                                                   //
//               ██        ██                                                 //
//              ███  █  █  ███    CCBNode_Loader_PropertySetters.h            //
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

#ifndef __MonsterFramework_src_Graphics_private_CCBNodeLoader_PropertySetters_h__
#define __MonsterFramework_src_Graphics_private_CCBNodeLoader_PropertySetters_h__

//MonsterFramework
#include "MonsterFramework/include/Graphics/ILoadResolver.h"
#include "MonsterFramework/include/Utils/MonsterFramework_Utils.h"

NS_MF_BEGIN

void _set_anchorPoint                 (cc::Node *obj, const cc::Value &value);
void _set_block                       (cc::Node *obj, const cc::Value &value, mf::ILoadResolver *pResolver);
void _set_color                       (cc::Node *obj, const cc::Value &value);
void _set_contentSize                 (cc::Node *obj, const cc::Value &value);
void _set_dimensions                  (cc::Node *obj, const cc::Value &value);
void _set_disabledSpriteFrame         (cc::Node *obj, const cc::Value &value);
void _set_displayFrame                (cc::Node *obj, const cc::Value &value);
void _set_fontName                    (cc::Node *obj, const cc::Value &value);
void _set_fontSize                    (cc::Node *obj, const cc::Value &value);
void _set_horizontalAlignment         (cc::Node *obj, const cc::Value &value);
void _set_ignoreAnchorPointForPosition(cc::Node *obj, const cc::Value &value);
void _set_isAccelerometerEnabled      (cc::Node *obj, const cc::Value &value);
void _set_isEnabled                   (cc::Node *obj, const cc::Value &value);
void _set_isTouchEnabled              (cc::Node *obj, const cc::Value &value);
void _set_normalSpriteFrame           (cc::Node *obj, const cc::Value &value);
void _set_opacity                     (cc::Node *obj, const cc::Value &value);
void _set_position                    (cc::Node *obj, const cc::Value &value);
void _set_rotation                    (cc::Node *obj, const cc::Value &value);
void _set_scale                       (cc::Node *obj, const cc::Value &value);
void _set_selectedSpriteFrame         (cc::Node *obj, const cc::Value &value);
void _set_string                      (cc::Node *obj, const cc::Value &value);
void _set_verticalAlignment           (cc::Node *obj, const cc::Value &value);

NS_MF_END
#endif // defined(__MonsterFramework_src_Graphics_private_CCBNodeLoader_PropertySetters_h__) //
