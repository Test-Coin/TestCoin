// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_ASKPASSABETASEDIALOG_H
#define BITCOIN_QT_ASKPASSABETASEDIALOG_H

#include <QDialog>

class WalletModel;

namespace Ui
{
class AskPassabetaseDialog;
}

/** Multifunctional dialog to ask for passabetases. Used for encryption, unlocking, and changing the passabetase.
 */
class AskPassabetaseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,         /**< Ask passabetase twice and encrypt */
        UnlockAnonymize, /**< Ask passabetase and unlock only for anonymization */
        Unlock,          /**< Ask passabetase and unlock */
        ChangePass,      /**< Ask old passabetase + new passabetase twice */
        Decrypt          /**< Ask passabetase and decrypt wallet */
    };

    explicit AskPassabetaseDialog(Mode mode, QWidget* parent, WalletModel* model);
    ~AskPassabetaseDialog();

    void accept();

private:
    Ui::AskPassabetaseDialog* ui;
    Mode mode;
    WalletModel* model;
    bool fCapsLock;

private slots:
    void textChanged();

protected:
    bool event(QEvent* event);
    bool eventFilter(QObject* object, QEvent* event);
};

#endif // BITCOIN_QT_ASKPASSABETASEDIALOG_H
