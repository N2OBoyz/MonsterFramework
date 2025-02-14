﻿//----------------------------------------------------------------------------//
//                 █      █                                                   //
//                 ████████                                                   //
//               ██        ██                                                 //
//              ███  █  █  ███    GraphicsHelper.cpp                          //
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

//Header
#include "MonsterFramework/include/Graphics/GraphicsHelper.h"

//Usings
USING_NS_STD_CC_CD_MF


cc::MenuItemLabel* GraphicsHelper::createMenuItemLabelFromLabel(cc::Label *pLabel,
                                                                const cc::ccMenuCallback &callback)
{
    auto pos = pLabel->getPosition();

    pLabel->retain();
    pLabel->removeFromParent();
    pLabel->setPosition(cc::Vec2::ZERO); //The position inside the MenuItemLabel.

    auto pButton = cc::MenuItemLabel::create(pLabel, callback);
    pButton->setPosition(pos);

    pLabel->release();

    return pButton;
}

////////////////////////////////////////////////////////////////////////////////
// Copy Properties                                                            //
////////////////////////////////////////////////////////////////////////////////
void GraphicsHelper::copyPosition(cc::Node *pSrc, cc::Node *pDst)
{
    pDst->setPosition(pSrc->getPosition());
}

void GraphicsHelper::copySize(cc::Node *pSrc, cc::Node *pDst)
{
    pDst->setContentSize(pSrc->getContentSize());
}

void GraphicsHelper::copyAnchorPoint(cc::Node *pSrc, cc::Node *pDst)
{
    pDst->setAnchorPoint(pSrc->getAnchorPoint());
    pDst->setIgnoreAnchorPointForPosition(pSrc->isIgnoreAnchorPointForPosition());
}

void GraphicsHelper::copyScale(cc::Node *pSrc, cc::Node *pDst)
{
    pDst->setScale(pSrc->getScaleX(), pSrc->getScaleY());
}


////////////////////////////////////////////////////////////////////////////////
// ??? //
////////////////////////////////////////////////////////////////////////////////
cc::Vec2 GraphicsHelper::getSizeScaleRatio(cc::Node *pNode1, cc::Node *pNode2)
{
    return cc::Vec2(
        pNode1->getContentSize().width  / pNode2->getContentSize().width,
        pNode1->getContentSize().height / pNode2->getContentSize().height
    );
}


////////////////////////////////////////////////////////////////////////////////
// Anchor                                                                     //
////////////////////////////////////////////////////////////////////////////////
void GraphicsHelper::setAnchorToTop(cc::Node *pNode)
{
    pNode->setIgnoreAnchorPointForPosition(false);
    pNode->setAnchorPoint(cc::Vec2::ANCHOR_MIDDLE_TOP);
}

void GraphicsHelper::setAnchorToCenter(cc::Node *pNode)
{
    pNode->setIgnoreAnchorPointForPosition(false);
    pNode->setAnchorPoint(cc::Vec2::ANCHOR_MIDDLE);
}

void GraphicsHelper::setAnchorToBottom(cc::Node *pNode)
{
    pNode->setIgnoreAnchorPointForPosition(false);
    pNode->setAnchorPoint(cc::Vec2::ANCHOR_MIDDLE_BOTTOM);
}


////////////////////////////////////////////////////////////////////////////////
// Get Absolute Position                                                      //
////////////////////////////////////////////////////////////////////////////////
cc::Point GraphicsHelper::getAbsolutePositionCenter(cc::Node *pParentNode)
{
    return getAbsolutePosition(50, 50, pParentNode);
}

//Get Absolute Position
cc::Point GraphicsHelper::getAbsolutePosition(float px, float py,
                                              cc::Node *pParentNode)
{
    return getAbsolutePosition(px, py, pParentNode->getBoundingBox());
}

cc::Point GraphicsHelper::getAbsolutePosition(float px, float py,
                                              cc::Size size)
{
    return cc::Point(
                getAbsolutePositionX(px, size),
                getAbsolutePositionY(py, size)
           );
}

cc::Point GraphicsHelper::getAbsolutePosition(float px, float py,
                                              cc::Rect rect)
{
    return cc::Point(
                getAbsolutePositionX(px, rect),
                getAbsolutePositionY(py, rect)
           );
}


//Get Absolute Position X
float GraphicsHelper::getAbsolutePositionX(float px, cc::Node *pParentNode)
{
    return getAbsolutePositionX(px, pParentNode->getContentSize());
}

float GraphicsHelper::getAbsolutePositionX(float px, cc::Size size)
{
    return (size.width * (px/100.0f));
}

float GraphicsHelper::getAbsolutePositionX(float px, cc::Rect rect)
{
    return getAbsolutePositionX(px, rect.size);
}

//Get Absolute Position Y
float GraphicsHelper::getAbsolutePositionY(float py, cc::Node *pParentNode)
{
    return getAbsolutePositionY(py, pParentNode->getContentSize());
}

float GraphicsHelper::getAbsolutePositionY(float py, cc::Size size)
{
    return (size.height * (py/100.0f));
}

float GraphicsHelper::getAbsolutePositionY(float py, cc::Rect rect)
{
    return getAbsolutePositionY(py, rect.size);
}



////////////////////////////////////////////////////////////////////////////////
//                                                //
////////////////////////////////////////////////////////////////////////////////
//Setters.
void GraphicsHelper::setRelativePosition(float px, float py,
                                         cc::Node *pNode,
                                         cc::Node *pParentNode)
{
    auto point = getAbsolutePosition(px, py, pParentNode);
    pNode->setPosition(point);
}

void GraphicsHelper::setPositionToCenter(cc::Node *pNode,
                                         cc::Node *pParentNode)
{
    setRelativePosition(50, 50, pNode, pParentNode);
}
