/*
 * windefs.c: default settings that are specific to Windows.
 */

#include "putty.h"

#include <commctrl.h>

FontSpec *platform_default_fontspec(const char *name)
{
    /* PuttyTray hack / System Font ... Check windows version and set default font to 'consolas' if this is >XP (3 lines) */
    OSVERSIONINFO versioninfo;
    versioninfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&versioninfo);

    if (!strcmp(name, "Font"))
        /* PuttyTray hack / System Font ... Check windows version and set default font to 'consolas' if this is >XP (3 lines) */
        if (versioninfo.dwMajorVersion >= 6) {
        return fontspec_new("Consolas", 0, 8, ANSI_CHARSET);
        } else {
        return fontspec_new("Courier New", 0, 10, ANSI_CHARSET);
        } /* PuttyTray hack / System Font ... balancing brace added */
    else
        return fontspec_new("", 0, 0, 0);
}

Filename *platform_default_filename(const char *name)
{
    if (!strcmp(name, "LogFileName"))
	return filename_from_str("putty.log");
    else
	return filename_from_str("");
}

char *platform_default_s(const char *name)
{
    if (!strcmp(name, "SerialLine"))
	return dupstr("COM1");
    return NULL;
}

int platform_default_i(const char *name, int def)
{
    return def;
}
