TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    core/boxcore.cpp \
    modules/help_module/helpmodule.cpp \
    modules/machine_module/machinemodule.cpp \
    modules/machine_module/sub-modules/machinesubmoduleadd.cpp \
    modules/machine_module/sub-modules/machinesubmoduleedit.cpp \
    modules/machine_module/sub-modules/machinesubmoduleremove.cpp \
    modules/machine_module/sub-modules/machinesubmoduleperform.cpp \
    modules/machine_module/sub-modules/machinesubmoduleget.cpp \
    modules/framework/_errors/errorbase.cpp \
    modules/framework/_modules/modulebase.cpp \
    modules/network_module/networkmodule.cpp \
    modules/network_module/sub-modules/networkclient.cpp \
    modules/software_module/sub-modules/softwaresubmoduleinstall.cpp \
    modules/software_module/sub-modules/softwaresubmodulemodify.cpp \
    modules/software_module/sub-modules/softwaresubmoduleremove.cpp \
    modules/software_module/softwaremodule.cpp

HEADERS += \
    core/boxcore.h \
    core/modulebox.h \
    modules/moduledirectory.h \
    modules/returnitem.h \
    modules/returncodes.h \
    modules/errorbase.h \
    modules/framework/errorbase.h \
    core/modulebox.h \
    modules/help_module/helpmodule.h \
    core/datatypes.h \
    modules/machine_module/machinemodule.h \
    modules/machine_module/sub-modules/machinesubmoduleadd.h \
    modules/machine_module/machinemoduledirectory.h \
    modules/machine_module/sub-modules/machinesubmoduleedit.h \
    modules/machine_module/sub-modules/machinesubmoduleremove.h \
    modules/machine_module/sub-modules/machinesubmoduleperform.h \
    modules/machine_module/sub-modules/machinesubmoduleget.h \
    modules/framework/osincludes.h \
    modules/framework/_errors/errorbase.h \
    modules/framework/_modules/modulebase.h \
    modules/framework/_modules/moduledirectory.h \
    modules/framework/_os/osincludes.h \
    modules/framework/_os/osinfo.h \
    modules/framework/_types/returncodes.h \
    modules/framework/_types/returnitem.h \
    modules/network_module/networkmodule.h \
    modules/network_module/networkdirectory.h \
    modules/network_module/sub-modules/networkclient.h \
    modules/software_module/sub-modules/softwaresubmoduleinstall.h \
    modules/software_module/sub-modules/softwaresubmodulemodify.h \
    modules/software_module/sub-modules/softwaresubmoduleremove.h \
    modules/software_module/softwaremodule.h \
    modules/software_module/softwaremoduledirectory.h

DISTFILES += \
    work.todo \
    modules/help_module/pages/directory.conf \
    modules/help_module/pages/machine \
    lib/machine/example \
    lib/machine/adddomain.ps1 \
    lib/machine/adddomainfinal.bat \
    lib/machine/editDomain.ps1 \
    lib/machine/editWorkgroup.ps1 \
    lib/machine/removeDomain.ps1 \
    lib/machine/editCname.ps1 \
    lib/software/deployment.properties \
    lib/software/fixJava.bat \
    lib/machine/cleanup.bat \
    modules/help_module/pages/network \
    lib/machine/editUAC.bat \
    lib/machine/performUpdates.ps1 \
    lib/software/installJava.ps1 \
    lib/software/installJavaMac.sh \
    lib/software/removeJavaMac.sh \
    lib/software/fixJavaMac.sh \
    lib/software/removeKACEWin.ps1 \
    lib/software/installKACEWin.ps1 \
    lib/software/removeAviraWin.ps1

