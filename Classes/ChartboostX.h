/****************************************************************************
 Copyright (c) 2012      Wenbin Wang
 
 http://geeksavetheworld.com
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/


#ifndef ChartboostX_ChartboostX_h
#define ChartboostX_ChartboostX_h

#include "cocos2d.h"
#include "ChartboostXDelegate.h"

// Location constants
static const char* LOCATION_ACHIEVEMENTS    = "Achievements";
static const char* LOCATION_DEFAULT         = "Default";
static const char* LOCATION_GAME_SCREEN     = "Game Screen";
static const char* LOCATION_GAMEOVER        = "Game Over";
static const char* LOCATION_HOME_SCREEN     = "Home Screen";
static const char* LOCATION_IAP_STORE       = "IAP Store";
static const char* LOCATION_ITEM_STORE      = "GItem Store";
static const char* LOCATION_LEADERBOARD     = "Leaderboard";
static const char* LOCATION_LEVEL_COMPLETE  = "Level Complete";
static const char* LOCATION_LEVEL_START     = "Level Start";
static const char* LOCATION_MAIN_MENU       = "Main Menu";
static const char* LOCATION_PAUSE           = "Pause";
static const char* LOCATION_QUESTS          = "Quests";
static const char* LOCATION_QUIT            = "Quit";
static const char* LOCATION_SETTINGS        = "Settings";
static const char* LOCATION_STARTUP         = "Startup";
static const char* LOCATION_TURN_COMPLETE   = "Turn Complete";


class ChartboostX {
    
public:
    static ChartboostX* sharedChartboostX();
    static void purgeChartboostX();
    
    // Cache an interstitial, optionally takes a location argument
    void cacheInterstitial(const char* location);
    // check if an interstitial is stored in cache for a default location, or a specific location
    // Only valid in iOS
    // In Android, it will always return false, if the interstitial has cached when call this method,
    // ChartboostXDelegate::didCacheInterstitial(const char* location) will be call-back.
    bool hasInterstitial(const char* location);
    // Show an interstitial, optionally takes a location argument
    void showInterstitial(const char* location);

    // Cache the More Apps page
    void cacheMoreApps(const char* location);
    // check if an MoreApp is stored in cache for a default location, or a specific location
    // Only valid in iOS
    // In Android, it will always return false, if the interstitial has cached when call this method,
    // ChartboostXDelegate::didCacheMoreApp (const char* location) will be call-back.
    bool hasMoreApps(const char* location);
    // Show the More Apps page
    void showMoreApps(const char* location);
    
    // Cache the RewardedVideo page
    void cacheRewardedVideo(const char* location);
    // check if an RewardedVideo is stored in cache for a default location, or a specific location
    // Only valid in iOS
    // In Android, it will always return false, if the interstitial has cached when call this method,
    // ChartboostXDelegate::didCacheMoreApp (const char* location) will be call-back.
    bool hasRewardedVideo(const char* location);
    // Show the RewardedVideo page
    void showRewardedVideo(const char* location);

    //void setDelegate(ChartboostXDelegate* delegate) { m_delegate = delegate; }
    ChartboostXDelegate* getDelegate() { return m_delegate; }
    
private:
    ChartboostX()
    :m_delegate(new ChartboostXDelegate())
    {
        //m_delegate = new ChartboostXDelegate();
    }
    
    virtual ~ChartboostX()
    {
        delete m_delegate;
    }

    ChartboostXDelegate* m_delegate;
};

#endif // ChartboostX_ChartboostX_h
