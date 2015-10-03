#ifndef __STDAFX_H__
#define __STDAFX_H__

#pragma once

#define WIN32_LEAN_AND_MEAN

#pragma warning(disable: 4018 4244 4805 4309 4995 4996)

// Windows Header Files
#include "windows.h"

// C++ Runtime Header Files
#include <fstream>
#include <time.h>
#include <process.h>
#include <SQL.h>
#include <SqlExt.h>

// Security
#include <rpc.h>
#include <rpcdce.h>

// SQL
#include "SQL.h"

// Local Header Files
#include "Security.h"
#include "Log.h"
#include "Protocol.h"
#include "Item.h"
#include "User.h"
#include "Tools.h"
#include "Mapping.h"
#include "ReadScript.h"
#include "Fixes.h"
#include "Player.h"
#include "Structures.h"

// Customs
#include "GuildSystem.h"
#include "CustomJewels.h"
#include "ChaosMachine.h"
#include "Commands.h"
#include "StoneExchanger.h"

#define CUSTOM_PATH  ".\\Exillum.ini"

#endif