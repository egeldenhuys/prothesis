import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { PassionComponent } from './components/passion/passion.component';


const routes: Routes = [
  { path: 'passion', component: PassionComponent },
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
