#ifndef SOURCECODEPANE_H
#define SOURCECODEPANE_H

#include <QtGui/QWidget>
#include <QString>
#include <QList>
#include "asm.h" // For Code in QList<Code *> codeList;

namespace Ui {
    class SourceCodePane;
}

class SourceCodePane : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(SourceCodePane)
public:
    explicit SourceCodePane(QWidget *parent = 0);
    virtual ~SourceCodePane();

    bool assemble();
    // Pre: The source code pane contains a Pep/8 source program.
    // Post: If the program assembles correctly, true is returned, and codeList is populated
    // with the code objects. Otherwise false is returned and codeList is partially populated.
    // Post: Pep::symbolTable is populated with values not adjusted for .BURN.
    // Post: Pep::byteCount is the byte count for the object code not adjusted for .BURN.
    // Post: Pep::burnCount is the number of .BURN instructions encountered in the source program.

    QList<int> getObjectCode();
    // Pre: codeList is populated with code from a complete correct Pep/8 source program.
    // Post: objectCode is populated with the object code, one byte per entry, and returned.

    QStringList getAssemblerListingList();
    // Pre: codeList is populated with code from a complete correct Pep/8 source program.
    // Post: assemlberListingList is populated with the assembler listing.
    // Post: listingTraceList is populated with the object code.
    // Post: hasCheckBox is populated with the checkBox list that specifies whether a trace line can have a break point.
    // Post: assemblerListingList is returned.

    QStringList getListingTraceList();
    // Pre: listingTraceList is populated.
    // Post: ListingTraceList is returned.

    QList<bool> getHasCheckBox();
    // Pre: hasCheckBox is populated.
    // Post: hasCheckBox is returned.

    void adjustCodeList(int addressDelta);
    // Pre: codeList is populated with code from a complete correct Pep/8 source program.
    // Post: The memAddress field of each code object is incremented by addressDelta.

    void installOS();
    // Pre: objectCode is populated with code from a complete correct Pep/8 OS source program.
    // Post: objectCode is loaded into OS rom of Pep::Mem.

    bool installOSOnStartup();
    // Pre: nothing is yet in memory
    // Post: the pep/8 operating system is installed into memory, and true is returned
    // If assembly fails, false is returned
    // This function should only be called on program startup once

    void removeErrorMessages();
    // Post: Searces for the string ";ERROR:" on each line and removes the end of the line.
    // Post: Searces for the string ";WARNING:" on each line and removes the end of the line.

    void appendMessageInSourceCodePaneAt(int lineNumber, QString message, Qt::GlobalColor color);
    // Post: Appends message to the end of line lineNumber in color color.

    void setSourceCodePaneText(QString string);
    // Post: Sets text in source code pane to string.

    void clearSourceCode();
    // Post: Clears the source code pane

    bool isModified();
    // Post: Returns true if the source code pane has been modified

    void setModifiedFalse();
    // Post: Sets isModified of the source code pane to false

    QString toPlainText();
    // Post: Contents of the source code pane are returned

    void setCurrentFile(QString string);
    // Post: Title bar of the window is set to "Object Code - 'string'"

    void highlightOnFocus();
    // Post: Highlights the label based on the label window color saved in the UI file

    bool hasFocus();
    // Post: returns if the pane has focus

    void undo();
    // Post: the last action in the text edit is undone

    void redo();
    // Post: the last undo in the text edit is redone

    bool isUndoable;
    // The undoability of the text edit is stored here

    bool isRedoable;
    // The redoability of the text edit is stored here

    void cut();
    // Post: selected text in the text edit is cut to the clipboard

    void copy();
    // Post: selected text in the text edit is copied to the clipboard

    void paste();
    // Post: selected text in the clipboard is pasted to the text edit

private:
    Ui::SourceCodePane *m_ui;
    QList<Code *> codeList;
    QList<int> objectCode;
    QStringList assemblerListingList;
    QStringList listingTraceList;
    QList<bool> hasCheckBox;

private slots:
    void setLabelToModified(bool modified);
    void setUndoability(bool b);
    void setRedoability(bool b);

};

#endif // SOURCECODEPANE_H

