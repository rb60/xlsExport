#ifndef XLSEXPORT_H
#define XLSEXPORT_H

#include "qglobal.h"
#include "exportTypes.h"
#include <QList>

#ifdef Q_OS_WIN
#define МУ_EXPORT __declspec(dllexport)
#else
    #define МУ_EXPORT
#endif

class XlsExport : public ExportData
{
private:
    QList<char*> chars;
public:
    char *getName() override;
    int getParametrsCount() override;
    char *getParametrName(int index) override;
    int getParametrType(int index) override;
    void exportData(char **parametrs, TransferData *data) override;
    void destroy() override;


};

extern "C" МУ_EXPORT
{
    ExportData *getInstance();
}



#endif // XLSEXPORT_H
