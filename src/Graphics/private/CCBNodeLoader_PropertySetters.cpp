﻿//----------------------------------------------------------------------------//
//                 █      █                                                   //
//                 ████████                                                   //
//               ██        ██                                                 //
//              ███  █  █  ███    CCBNode_Loader_PropertySetters.cpp          //
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


//Header.
#include "CCBNodeLoader_PropertySetters.h"
//MonsterFramework.
#include "CCBNodeLoader_Decoders.h"
//std
#include <typeinfo>

USING_NS_STD_CC_CD_MF

////////////////////////////////////////////////////////////////////////////////
// Private Helper Functions                                                   //
// THE FOLLWING FUNCTIONS ARE ONLY HELPERS FOR THE PROPERTY SETTERS           //
// THE SHOULD NOT BE EXPOSED TO OUSIDE, SO THEM ARE DECLARED HERE             //
// AND DEFINED AT BOTTOM OF THIS SOURCE FILE.                                 //
// THE PURPOSE OF THEM IS TO HANDLE OF SOME NASTY THING ABOUT LOADING         //
// THE CCB...                                                                 //
////////////////////////////////////////////////////////////////////////////////
void _private_helper_setNormalSpriteFrameForMFToggle  (cc::Node *node, const cc::Value &value);
void _private_helper_setPressedSpriteFrameForMFToggle (cc::Node *node, const cc::Value &value);
void _private_helper_setDisabledSpriteFrameForMFToggle(cc::Node *node, const cc::Value &value);
void _private_helper_setSpriteFrameForToggle          (cc::Node *node, const cc::Value &value,
                                                       int index, bool setSelected);



////////////////////////////////////////////////////////////////////////////////
// Public Helper Functions                                                    //
// THIS IS THE IMPLEMENTATION OF FUNCTIONS DEFINED                            //
// AT CCBNodeLoader_PropertySetters.h"                                        //
////////////////////////////////////////////////////////////////////////////////
void mf::_set_anchorPoint(cc::Node *obj, const cc::Value &value)
{
    obj->setAnchorPoint(_decodeAsPoint(value));
}

void mf::_set_block(cc::Node *obj, const cc::Value &value, ILoadResolver *pResolver)
{
    pResolver->resolveMenuSelector(_decodeAsBlock(value),
                                   static_cast<cc::MenuItem *>(obj));
}

void mf::_set_color(cc::Node *obj, const cc::Value &value)
{
    static_cast<cc::LayerColor *>(obj)->setColor(_decodeAsColor3(value));
}

void mf::_set_contentSize(cc::Node *pObj, const cc::Value &value)
{
    pObj->setContentSize(_decodeAsSize(value, pObj));
}

void mf::_set_dimensions(cc::Node *pObj, const cc::Value &value)
{
    cc::Size decodedValue = _decodeAsSize(value, pObj);
    static_cast<cc::Label *>(pObj)->setDimensions(
        decodedValue.width,
        decodedValue.height
    );
}

void mf::_set_disabledSpriteFrame(cc::Node *obj, const cc::Value &value)
{
    //There's no information to set the sprite, this is due
    //the CocosBuild set the disabledSpriteFrame in plist even
    //if the user doesn't set any of them...
    if(_decodeAsSpriteFrame(value) == "")
        return;

    //Check if button is a toggle or not.
    //If is a toogle calls the specialized function to set its sprite frame.
    //This is needed because toogle uses a different aproach to set the frames.
    if(typeid(*obj) == typeid(cc::MenuItemToggle))
    {
        _private_helper_setDisabledSpriteFrameForMFToggle(obj, value);
    }
    else
    {
        cc::Sprite *sprite = cc::Sprite::create();
        mf::_set_displayFrame(sprite, value);
        static_cast<cc::MenuItemSprite *>(obj)->setDisabledImage(sprite);
    }
}

void mf::_set_displayFrame(cc::Node *obj, const cc::Value &value)
{
    static_cast<cc::Sprite *>(obj)->setSpriteFrame(_decodeAsSpriteFrame(value));
}

void mf::_set_fontName(cc::Node *obj, const cc::Value &value)
{
    //COWTODO: THIS IS A VERY VERY UGLY HACK.
    auto label = static_cast<cc::Label *>(obj);
    TTFConfig config = label->getTTFConfig();
    config.fontFilePath = value.asString();

    label->setTTFConfig(config);
}

void mf::_set_fontSize(cc::Node *obj, const cc::Value &value)
{
    //COWTODO: THIS IS A VERY VERY UGLY HACK.
    auto label = static_cast<cc::Label *>(obj);
    TTFConfig config = label->getTTFConfig();
    config.fontSize = _decodeAsFontScale(value);

    label->setTTFConfig(config);
}

void mf::_set_horizontalAlignment(cc::Node *obj, const cc::Value &value)
{
    //COWTODO: This should have another decode function.
    auto decodedValue = static_cast<TextHAlignment>(_decodeAsByte(value));
    static_cast<cc::Label *>(obj)->setHorizontalAlignment(decodedValue);
}

void mf::_set_ignoreAnchorPointForPosition(cc::Node *obj, const cc::Value &value)
{
    obj->setIgnoreAnchorPointForPosition(_decodeAsCheck(value));
}

void mf::_set_isAccelerometerEnabled(cc::Node *obj, const cc::Value &value)
{
    //COWTODO:: Ignoring by now, but must check what this method will do.
}

void mf::_set_isEnabled(cc::Node *obj, const cc::Value &value)
{
    static_cast<cc::MenuItem *>(obj)->setEnabled(_decodeAsCheck(value));
}

void mf::_set_isTouchEnabled(cc::Node *obj, const cc::Value &value)
{
    //COWTODO:: Ignoring by now, but must check what this method will do.
}

void mf::_set_normalSpriteFrame(cc::Node *obj, const cc::Value &value)
{
    //Check if button is a toggle or not.
    //If is a toogle calls the specialized function to set its sprite frame.
    //This is needed because toogle uses a different aproach to set the frames.
    if(typeid(*obj) == typeid(cc::MenuItemToggle))
    {
        _private_helper_setNormalSpriteFrameForMFToggle(obj, value);
    }
    else
    {
        cc::Sprite *sprite = cc::Sprite::create();
        mf::_set_displayFrame(sprite, value);

        static_cast<cc::MenuItemSprite *>(obj)->setNormalImage(sprite);
    }
}

void mf::_set_opacity(cc::Node *obj, const cc::Value &value)
{
    obj->setOpacity(_decodeAsByte(value));
}

void mf::_set_position(cc::Node *pObj, const cc::Value &value)
{
    pObj->setPosition(_decodeAsPosition(value, pObj));
}

void mf::_set_rotation(cc::Node *obj, const cc::Value &value)
{
    obj->setRotation(_decodeAsDegrees(value));
}

void mf::_set_scale(cc::Node *obj, const cc::Value &value)
{
    //EMSG: We're decided treat scale as a stand alone
    //property. So it's not depends of anything else.
    auto point = _decodeAsPoint(value);
    obj->setScale(point.x, point.y);
}

void mf::_set_selectedSpriteFrame(cc::Node *obj, const cc::Value &value)
{
    //Check if button is a toggle or not.
    //If is a toogle calls the specialized function to set its sprite frame.
    //This is needed because toogle uses a different aproach to set the frames.
    if(typeid(*obj) == typeid(cc::MenuItemToggle))
    {
        _private_helper_setPressedSpriteFrameForMFToggle(obj, value);
    }
    else
    {
        cc::Sprite *sprite = cc::Sprite::create();
        mf::_set_displayFrame(sprite, value);

        static_cast<cc::MenuItemSprite *>(obj)->setSelectedImage(sprite);
    }
}

void mf::_set_string(cc::Node *obj, const cc::Value &value)
{
    static_cast<cc::Label *>(obj)->setString(_decodeAsString(value));
}

void mf::_set_verticalAlignment(cc::Node *obj, const cc::Value &value)
{
    //COWTODO: This should have another decode function.
    auto decodedValue = static_cast<TextVAlignment>(_decodeAsByte(value));
    static_cast<cc::Label *>(obj)->setVerticalAlignment(decodedValue);
}


////////////////////////////////////////////////////////////////////////////////
// Private Helper Functions (Implementation)                                  //
// Check the comments at the top of this file                                 //
// to understand those functions...                                           //
////////////////////////////////////////////////////////////////////////////////
void _private_helper_setNormalSpriteFrameForMFToggle(cc::Node *node, const cc::Value &value)
{
    _private_helper_setSpriteFrameForToggle(node, value, 0, true);
}

void _private_helper_setPressedSpriteFrameForMFToggle(cc::Node *node, const cc::Value &value)
{
     _private_helper_setSpriteFrameForToggle(node, value, 1, false);
}
void _private_helper_setDisabledSpriteFrameForMFToggle(cc::Node *node, const cc::Value &value)
{
    _private_helper_setSpriteFrameForToggle(node, value, 3, false);
}

void _private_helper_setSpriteFrameForToggle(cc::Node *node, const cc::Value &value,
                                             int index, bool setSelected)
{
    auto toggle = static_cast<cc::MenuItemToggle *>(node);

    cc::Sprite *sprite1 = cc::Sprite::create();
    cc::Sprite *sprite2 = cc::Sprite::create();

    mf::_set_displayFrame(sprite1,  value);
    mf::_set_displayFrame(sprite2,  value);

    auto menuItem = cc::MenuItemSprite::create(sprite1, sprite2);

    auto &menuItems = toggle->getSubItems();
    menuItems.insert(index, menuItem);

    if(setSelected)
        toggle->setSelectedIndex(index);
}
