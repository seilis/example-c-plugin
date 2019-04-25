bin_PROGRAMS = plugintest
lib_LTLIBRARIES = libxmlplugin.la libjsonplugin.la

AM_LDFLAGS = -ldl
AM_CFLAGS = -std=gnu11 -O0 -Wall -Wextra -Werror -Wno-error=deprecated-declarations
ACLOCAL_AMFLAGS = -I m4

libxmlplugin_la_SOURCES = src/plugin_xml.c

libjsonplugin_la_SOURCES = src/plugin_json.c

plugintest_SOURCES = src/main.c
