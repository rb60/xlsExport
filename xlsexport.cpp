#include "xlsexport.h"

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

ExportData *getInstance()
{
    return new XlsExport;
}

char *XlsExport::getName()
{
    char* result = "Excel";
    chars.append(result);
    return result;
}

int XlsExport::getParametrsCount()
{
    return 1;
}

char *XlsExport::getParametrName(int index)
{
    char* result;
    if(index == 0)
    {
        result = "Path";
    }
    else
    {
        result = "";
    }
    chars.append(result);
    return result;
}

int XlsExport::getParametrType(int index)
{
    return ParametrType::SAVE_FILE_PATH;
}

void XlsExport::exportData(char **parametrs, TransferData *data)
{
    QString filePath(parametrs[0]);

    QXlsx::Document doc;
    for(int i = 0; i < data->getColumnCount(); i++)
    {
        doc.write(1, i + 2, QString(data->getColumnName(i)));
    }

    for(int i = 0; i < data->getRowCount(); i++)
    {
        doc.write(i + 2, 1, QString(data->getRowName(i)));
    }

    for(int i = 0; i < data->getRowCount(); i++)
    {
        for(int j = 0; j < data->getColumnCount(); j++)
        {
            doc.write(i + 2, j + 2, data->getValue(i,j));
        }
    }

    doc.saveAs(filePath);

}

void XlsExport::destroy()
{
    for(int i = 0; i < chars.size(); i++)
    {
        delete[] chars[i];
    }
    delete this;
}
