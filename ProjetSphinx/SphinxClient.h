/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SphinxClient.h
 * Author: eleve
 *
 * Created on 22 février 2017, 09:35
 */

#ifndef _SPHINXCLIENT_H
#define _SPHINXCLIENT_H

#include "ui_SphinxClient.h"

class SphinxClient : public QDialog {
    Q_OBJECT
public:
    SphinxClient();
    virtual ~SphinxClient();
    void on_boutonConnexion_clicked();
private:
    Ui::SphinxClient widget;
};

#endif /* _SPHINXCLIENT_H */
