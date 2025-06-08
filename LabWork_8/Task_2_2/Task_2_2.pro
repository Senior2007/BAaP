QT += core gui widgets
TARGET = Task_2_2
CONFIG += c++17

MAC_LIB_DIR = /Users/senior/Desktop/BSUIR/ОАиП/QT/LabWork_8/BinaryHeapDLL/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug
LIB_BASE_NAME = BinaryHeapDLL

macx {
    LIBS += -L$$MAC_LIB_DIR -l$$LIB_BASE_NAME

    QMAKE_RPATHDIR += @loader_path/../Frameworks

    QMAKE_POST_LINK += mkdir -p $$OUT_PWD/Task_2_2.app/Contents/Frameworks && \
                      cp -f $$MAC_LIB_DIR/lib$$LIB_BASE_NAME.dylib $$OUT_PWD/Task_2_2.app/Contents/Frameworks/lib$$LIB_BASE_NAME.1.dylib && \
                      install_name_tool -id @rpath/lib$$LIB_BASE_NAME.1.dylib $$OUT_PWD/Task_2_2.app/Contents/Frameworks/lib$$LIB_BASE_NAME.1.dylib && \
                      install_name_tool -change lib$$LIB_BASE_NAME.dylib @rpath/lib$$LIB_BASE_NAME.1.dylib $$OUT_PWD/Task_2_2.app/Contents/MacOS/Task_2_2
}

INCLUDEPATH += /Users/senior/Desktop/BSUIR/ОАиП/QT/LabWork_8/BinaryHeapDLL
DEPENDPATH += /Users/senior/Desktop/BSUIR/ОАиП/QT/LabWork_8/BinaryHeapDLL

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
