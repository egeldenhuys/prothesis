import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import {NgbModule} from '@ng-bootstrap/ng-bootstrap';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { LongQuestionPanelComponent } from './components/long-question-panel/long-question-panel.component';
import { PassionComponent } from './components/passion/passion.component';
import { CheckboxPanelComponent } from './components/checkbox-panel/checkbox-panel.component';

@NgModule({
  declarations: [
    AppComponent,
    LongQuestionPanelComponent,
    PassionComponent,
    CheckboxPanelComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    NgbModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
