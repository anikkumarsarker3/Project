from django.contrib import admin
from .models import UserProfile, Job, Application
# Register your models here.
admin.site.register(UserProfile)
admin.site.register(Job)
admin.site.register(Application)