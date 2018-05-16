$NetBSD: patch-src_ck-sysdeps-netbsd.c,v 1.2 2018/05/16 11:30:36 youri Exp $

Fix NetBSD build and allow hibernation.

--- src/ck-sysdeps-netbsd.c.orig	2017-06-02 01:31:44.000000000 +0000
+++ src/ck-sysdeps-netbsd.c
@@ -36,7 +36,6 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/sysctl.h>
-#include <sys/user.h>
 #include <sys/ioctl.h>
 
 #ifdef HAVE_SYS_MOUNT_H
@@ -440,40 +439,13 @@ ck_get_active_console_num (int    consol
 gboolean
 ck_system_can_suspend (void)
 {
-        static const char acpi_sleep_mibname[] = "hw.acpi.sleep.states";
-        static const char acpi_suspend_state[] = "S3";
-        size_t state_len = 0;
-	int apm_fd = -1;
-
-        if (sysctlbyname (acpi_sleep_mibname, NULL, &state_len, NULL, 0) == 0) {
-                gchar *sleep_states = g_new (char, state_len + 1);
-                if (sysctlbyname (acpi_sleep_mibname, sleep_states, &state_len, NULL, 0) == 0) {
-                        sleep_states[state_len] = 0;
-                        if (strstr (sleep_states, acpi_suspend_state) != NULL) {
-                                g_free (sleep_states);
-                                return TRUE;
-			}
-                } else {
-                        g_free (sleep_states);
-                }
-        }
-        if (sysctlbyname ("machdep.xen.suspend", NULL, NULL, NULL, 0) == 0) {
-                return TRUE;
-        }
-
-        apm_fd = open ("/dev/apmctl", O_RDWR);
-        if(apm_fd == -1) {
-                return FALSE;
-        }
-        close(apm_fd);
-        return TRUE;
+	return TRUE;
 }
 
 gboolean
 ck_system_can_hibernate (void)
 {
-        /* TODO: not implemented */
-        return FALSE;
+	return TRUE;
 }
 
 gboolean
@@ -494,7 +466,11 @@ ck_make_tmpfs (guint uid, guint gid, con
 
         opts = g_strdup_printf ("mode=0700,uid=%d", uid);
 
+#ifdef __NetBSD__
+	result = mount("tmpfs", dest, 0, opts, strlen(opts));
+#else
         result = mount("tmpfs", dest, 0, opts);
+#endif
 
         g_free (opts);
 
