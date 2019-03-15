// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_ASKPASSABETASEDIALOG_H
#define BITCOIN_QT_ASKPASSABETASEDIALOG_H

#include <QDialog>

class WalletModel;

namespace Ui
{
class AskPassphraseDialog;
}

/** Multifunctional dialog to ask for passabetases. Used for encryption, unlocking, and changing the passabetase.
 */
class AskPassphraseDialog : public QDialog
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

    explicit AskPassphraseDialog(Mode mode, QWidget* parent, WalletModel* model);
    ~AskPassphraseDialog();

    void accept();

private:
    Ui::AskPassphraseDialog* ui;
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
