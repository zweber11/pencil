######################################################################
# Automatically generated by qmake (2.01a) sam. janv. 13 17:20:35 2007
######################################################################

TEMPLATE = subdirs
SUBDIRS = \
        core_lib \
        app \
        tests \
        3rdlib/quazip

core_lib.depends = 3rdlib/quazip
app.depends = core_lib
tests.depends = core_lib

