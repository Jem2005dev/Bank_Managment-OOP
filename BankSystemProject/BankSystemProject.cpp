#include<iostream>
#include "clsLoginScreen.h"

int main()
{
	while (true)
	{
		if (!clsLoginScreen::LogInScreen())
		{
			break;
		}
	}

	system("pause>0");

	return 0;
}