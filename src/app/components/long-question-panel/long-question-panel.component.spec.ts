import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { LongQuestionPanelComponent } from './long-question-panel.component';

describe('LongQuestionPanelComponent', () => {
  let component: LongQuestionPanelComponent;
  let fixture: ComponentFixture<LongQuestionPanelComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ LongQuestionPanelComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(LongQuestionPanelComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
