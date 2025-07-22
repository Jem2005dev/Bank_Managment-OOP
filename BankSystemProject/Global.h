#pragma once

#include<iostream>
#include "clsUser.h"

using namespace std;

namespace 
{
	extern clsUser CurrentUser = clsUser::Find("", "");
}
