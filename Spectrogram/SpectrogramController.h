#ifndef SPECTROGRAMCONTROLLER_H
#define SPECTROGRAMCONTROLLER_H

#include "SpectrogramModel.h"
#include "Spectrogram.h"

class SpectrogramController
{
public:
    SpectrogramController();
    void setModel(SpectrogramModel* pModel) { m_pModel = pModel; }
    void setView(Spectrogram* pView) { m_pView = pView; }

private:
    SpectrogramModel* m_pModel;
    Spectrogram* m_pView;
};

#endif // SPECTROGRAMCONTROLLER_H
