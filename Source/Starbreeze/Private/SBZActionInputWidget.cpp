#include "SBZActionInputWidget.h"

void USBZActionInputWidget::SetAction(FName InActionName, bool bShouldConsumeInput) {
}

void USBZActionInputWidget::OnActionReleased() {
}

void USBZActionInputWidget::OnActionPressed() {
}



USBZActionInputWidget::USBZActionInputWidget() {
    this->bConsumeInput = false;
    this->bIsActionPressed = false;
    this->KeyWidget = NULL;
    this->bIsIconVisibleForKeyboardAndMouse = true;
}

