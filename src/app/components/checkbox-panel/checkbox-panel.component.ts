import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-checkbox-panel',
  templateUrl: './checkbox-panel.component.html',
  styleUrls: ['./checkbox-panel.component.css']
})
export class CheckboxPanelComponent implements OnInit {

  @Input() options: String[];
  
  constructor() { }

  ngOnInit() {
  }

}
