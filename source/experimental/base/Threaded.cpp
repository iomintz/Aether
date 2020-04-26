#include "Threaded.hpp"

namespace Aether::Exp {
    Threaded::Threaded(ThreadQueue * q, RenderType r) {
        this->renderType = r;
        this->status = ThreadedStatus::Empty;
        this->surface = nullptr;
        this->tq = q;
    }

    void Threaded::createSurface() {
        this->status == ThreadedStatus::Queued;
        this->tq->addTask([this]() {
            this->generateSurface();
            this->status = ThreadedStatus::Surface;
        });
    }

    bool Threaded::startRendering() {
        ThreadedStatus st = this->status;
        if ((st == ThreadedStatus::Empty || st == ThreadedStatus::Texture) && this->tq != nullptr) {
            this->createSurface();
            return true;
        }
        return false;
    }

    bool Threaded::textureReady() {
        return (this->status == ThreadedStatus::Texture);
    }

    void Threaded::updateState() {
        if (this->status == ThreadedStatus::Surface) {
            this->convertSurface();
            this->status = ThreadedStatus::Texture;
        }
    }

    Threaded::~Threaded() {
        if (this->surface != nullptr) {
            SDLHelper::freeSurface(this->surface);
        }
    }
};