include(../sparql-examples.pri)

SOURCES       = main.cpp
#QT           += sparql # enable this later

# install FIXME
target.path = $$[QT_INSTALL_EXAMPLES]/sparql/iteration
sources.files = $$SOURCES *.h $$RESOURCES $$FORMS iteration.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/sparql/iteration
INSTALLS += target sources