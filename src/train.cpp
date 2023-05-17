// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train(): countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
  if (first != nullptr) {
    Cage* newVag;
    newVag = new Cage;
    newVag->light = light;
    newVag->next = nullptr;
    newVag->prev = last;
    last->next = newVag;
    last = newVag;
  } else {
      first = new Cage;
      first->light = light;
      first->next = nullptr;
      first->prev = nullptr;
      last = first;
      return;
  }
}
int Train::getLength() {
  first->light = true;
  first->prev = last;
  last->next = first;
  Cage* cur = first;
  Cage* vl = first->next;
  while (vl != nullptr) {
    if (!vl->light) {
      cnt++;
      countOp++;
      vl = vl->next;
    } else {
        if (vl->light) {
          vl->light = 0;
          countOp++;
        }
        for (int i = cnt; i > 0; i--) {
          vl = vl->prev;
          countOp++;
        }
        if (!vl->light) {
          break;
        } else {
            vl = vl->next;
            cnt = 1;
        }
    }
  }
  return cnt;
}

int Train::getOpCount() {
  return countOp;
}
