#pragma once
namespace sessionInfo {

}
class CurrentSessionInfo
{
private:
	static bool isUserAdmin;
	//User currUser;
public:
	static void SetAdmin(bool isAdmin);
	static bool CheckIfAdmin();
	//void SetUser();
	//User GetCurrUser();
};

