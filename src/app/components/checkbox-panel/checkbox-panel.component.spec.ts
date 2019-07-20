import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { CheckboxPanelComponent } from './checkbox-panel.component';

describe('CheckboxPanelComponent', () => {
  let component: CheckboxPanelComponent;
  let fixture: ComponentFixture<CheckboxPanelComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ CheckboxPanelComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(CheckboxPanelComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
