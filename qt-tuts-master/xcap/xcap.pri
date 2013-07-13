# REFERENCE: http://stackoverflow.com/questions/1565732/libqxt-under-qt-creator
# http://dev.libqxt.org/libqxt/wiki/user_guide

QXT_DIR = libqxt
LIBS += -L$${QXT_DIR}/lib
INCLUDEPATH += $${QXT_DIR}/include
for(module, QXT) {
    MODNAME = $$upper($$replace(module, "(.).*", "\1"))$$replace(module, "^.", "")
    INCLUDEPATH += $${QXT_DIR}/include/Qxt$${MODNAME}
    INCLUDEPATH += $${QXT_DIR}/src/$${module}
    win32:CONFIG(debug, debug|release):MODNAME = $$join(MODNAME,,,d)
    LIBS += -lQxt$${MODNAME}
}
