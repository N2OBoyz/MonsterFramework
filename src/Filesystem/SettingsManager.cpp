﻿//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        SettingsManager.cpp                       //
//            █ █        █ █        MonsterFramework                          //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
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
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

//Header
#include "MonsterFramework/include/Filesystem/SettingsManager.h"
//Platform
#include "MonsterFramework/include/Platform/Application.h"
//Storage.
#include "./private/BasicStorage.h"

//Usings
USING_NS_STD_CC_CD_MF

////////////////////////////////////////////////////////////////////////////////
// Constants                                                                  //
////////////////////////////////////////////////////////////////////////////////
constexpr auto kSettingsManagerDatabaseName = ".%s_MONSTERFRAMEWORK_SETTINGSMANAGER_DB.db";


////////////////////////////////////////////////////////////////////////////////
// Private CTOR / DTOR                                                        //
////////////////////////////////////////////////////////////////////////////////
SettingsManager::SettingsManager()
{
    //COWTODO: The Database should be placed inside a hidden
    //         folder with the name of the application.
    auto pApplication = static_cast<mf::Application *>(mf::Application::getInstance());

    auto appName   = pApplication->getApplicationName();
    auto writePath = FileUtils::getInstance()->getWritablePath();
    
    m_path = writePath + cc::StringUtils::format(
       kSettingsManagerDatabaseName,
       appName.c_str()
    );

    MF_LOG_EX(
        "SettingsManager::SettignsManager",
        "Settings write path is: (%s)",
        m_path.c_str()
    );
    
    //Initialize the unique_ptr.
    // BasicStorage implements RAII.
    m_pStorage.reset(new BasicStorage(m_path));
}

SettingsManager::~SettingsManager()
{
    //Empty..
}


////////////////////////////////////////////////////////////////////////////////
// Public Methods                                                             //
////////////////////////////////////////////////////////////////////////////////
//Remove
void SettingsManager::removeItem(const std::string &key)
{
    m_pStorage->removeItem(key);
}

void SettingsManager::removeAllItems()
{
    m_pStorage->removeAllItems();
}

//Other
const string& SettingsManager::getStoragePath()
{
    return m_path;
}

////////////////////////////////////////////////////////////////////////////////
// Private Methods                                                            //
////////////////////////////////////////////////////////////////////////////////
std::string SettingsManager::_getValueForKey(const std::string &key,
                                             bool *pExists)
{
    return m_pStorage->getItem(key, pExists);;
}

void SettingsManager::_setValueForKey(const std::string &key,
                                      const std::string &value)
{
    m_pStorage->setItem(key, value);
}
