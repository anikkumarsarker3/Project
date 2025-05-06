from django.urls import path
from . import views

urlpatterns = [
    path('signup/',  views.signup_view,  name='signup'),
    path('login/',   views.login_view,   name='login'),
    path('logout/',  views.logout_view,  name='logout'),

    path('',          views.job_list,    name='job_list'),
    path('jobs/<int:pk>/',        views.job_detail,    name='job_detail'),
    path('jobs/create/',          views.job_create,    name='job_create'),
    path('jobs/<int:pk>/edit/',   views.job_edit,      name='job_edit'),
    path('jobs/<int:pk>/delete/', views.job_delete,    name='job_delete'),
    path('jobs/<int:pk>/apply/',  views.apply_job,     name='apply_job'),
]
