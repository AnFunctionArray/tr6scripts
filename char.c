native SetCurrentLevel(lvln)
native InitialiseNewGame()
native SetGameState(state)
native PlayFMV(const str[])
native amx_Menu(lcl)
native LoadLevel(const dir[], const level[])
native ReturnString(const str[])
native ReturnInt(in)
native amx_Settings()
native BeginLoad(const dir[], const level[], lclid)
native EndLoad()
native GetGameState()
native printf(const str[],...)
native PlayControl(charnode)
native GetCharFlags(charnode)
native GetAnimVelocity(charnode, vel[])
native ApplyAnimVelocity(charnode, vel[])
native mapGetPlayerOrientation(ori[])
native SetOrientation(charnode, ori[])
native GetRightDirection(charnode, dir[])
native mathVectorDot(mat4[], mat42[])
native Ragdoll(charnode)
native sysGetFrameCount_AMX(charnode)
native mapStopPlayerAnimation(charnode)
native mapStartPlayerAnimation(charnode)
native mapGetDBPadAMX(id)
native IsButtonPressed(id, mask)
native GetAnimation(charnode)
native GetUserValue(base, offset) //[base+offset*4+120h]

public OnUpdate(charnode)
{

	new vel[4]
	new animid = GetAnimation(charnode)//0x75209033
	if (animid == 0x75209033) {
		printf ("anim id %x", animid)
		for (new i = 0; i <= 7; ++i) {
				new test = mapGetDBPadAMX(i)
				if (test)
					printf("dir %d is %x;", i, test)
			}
			
		for (new i = 0; i <= 1; ++i) {
			new test = IsButtonPressed(i, 0xFFFFFFFF)
			if (test)
				printf("button %d is %x;", i, test)
		}
	}
	else {
		/**/
		//new ori[4]
		//new rdir[4]
		GetAnimVelocity(charnode, vel)
		//mapGetPlayerOrientation(ori)
		//GetRightDirection(charnode, rdir)
		//mathVectorDot(ori, rdir)
		//mathVectorDot(ori, vel)
		PlayControl(charnode)
		//new flags = GetCharFlags(charnode)
		ApplyAnimVelocity(charnode, vel)
		//SetOrientation(charnode, ori)
	}
	exit charnode
}
