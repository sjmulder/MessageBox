#include <stdio.h>
#include <windows.h>

#define LEN(x) (sizeof(x)/sizeof(*(x)))

struct { char nm[29]; UINT val; } flagmap[] = {
	{ "MB_OK", MB_OK },
	{ "MB_OKCANCEL", MB_OKCANCEL },
	{ "MB_ABORTRETRYIGNORE", MB_ABORTRETRYIGNORE },
	{ "MB_YESNOCANCEL", MB_YESNOCANCEL },
	{ "MB_YESNO", MB_YESNO },
	{ "MB_RETRYCANCEL", MB_RETRYCANCEL },
	{ "MB_CANCELTRYCONTINUE", MB_CANCELTRYCONTINUE },
	{ "MB_ICONHAND", MB_ICONHAND },
	{ "MB_ICONQUESTION", MB_ICONQUESTION },
	{ "MB_ICONEXCLAMATION", MB_ICONEXCLAMATION },
	{ "MB_ICONASTERISK", MB_ICONASTERISK },
	{ "MB_USERICON", MB_USERICON },
	{ "MB_ICONWARNING", MB_ICONWARNING },
	{ "MB_ICONERROR", MB_ICONERROR },
	{ "MB_ICONINFORMATION", MB_ICONINFORMATION },
	{ "MB_ICONSTOP", MB_ICONSTOP },
	{ "MB_DEFBUTTON1", MB_DEFBUTTON1 },
	{ "MB_DEFBUTTON2", MB_DEFBUTTON2 },
	{ "MB_DEFBUTTON3", MB_DEFBUTTON3 },
	{ "MB_DEFBUTTON4", MB_DEFBUTTON4 },
	{ "MB_APPLMODAL", MB_APPLMODAL },
	{ "MB_SYSTEMMODAL", MB_SYSTEMMODAL },
	{ "MB_TASKMODAL", MB_TASKMODAL },
	{ "MB_HELP", MB_HELP },
	{ "MB_NOFOCUS", MB_NOFOCUS },
	{ "MB_SETFOREGROUND", MB_SETFOREGROUND },
	{ "MB_DEFAULT_DESKTOP_ONLY", MB_DEFAULT_DESKTOP_ONLY },
	{ "MB_TOPMOST", MB_TOPMOST },
	{ "MB_RIGHT", MB_RIGHT },
	{ "MB_RTLREADING", MB_RTLREADING },
	{ "MB_SERVICE_NOTIFICATION", MB_SERVICE_NOTIFICATION },
	{ "MB_SERVICE_NOTIFICATION_NT3X", MB_SERVICE_NOTIFICATION_NT3X },
	{ "MB_TYPEMASK", MB_TYPEMASK },
	{ "MB_ICONMASK", MB_ICONMASK },
	{ "MB_DEFMASK", MB_DEFMASK },
	{ "MB_MODEMASK", MB_MODEMASK },
	{ "MB_MISCMASK", MB_MISCMASK }
};

int main(int argc, char **argv)
{
	int i, j;
	UINT flags;

	if (argc < 3) {
		fprintf(stderr, "Usage: MessageBox <text> <title> "
			"[<flag> ..]\n\nFlags:\n");
		for (i = 0; i < LEN(flagmap); i++)
			fprintf(stderr, "  %s\n", flagmap[i].nm);
		exit(1);
	}

	for (i = 3; i < argc; i++) {
		for (j = 0; j < LEN(flagmap); j++) {
			if (strcmp(argv[i], flagmap[j].nm))
				continue;
			flags |= flagmap[j].val;
			break;
		}

		if (j == LEN(flagmap)) {
			fprintf(stderr, "Unknown flag: %s\n", argv[i]);
			exit(1);
		}
	}

	return MessageBox(NULL, argv[2], argv[1], flags);
}
