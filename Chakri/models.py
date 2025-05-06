from django.db import models
from django.contrib.auth.models import User
from django.db.models.signals import post_save
from django.dispatch import receiver
class UserProfile(models.Model):
    ROLES = (('seeker','Job Seeker'),('employer','Employer'))
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    role = models.CharField(max_length=10, choices=ROLES)

class Job(models.Model):
    JOB_TYPES = (
        ('full_time','Full Time'),
        ('part_time','Part Time'),
        ('remote','Remote'),
    )
    title        = models.CharField(max_length=200)
    description  = models.TextField()
    location     = models.CharField(max_length=100)
    salary_range = models.CharField(max_length=100)
    job_type     = models.CharField(max_length=20, choices=JOB_TYPES)
    created_date = models.DateTimeField(auto_now_add=True)
    employer     = models.ForeignKey(User, on_delete=models.CASCADE)
    is_active    = models.BooleanField(default=True)

    def __str__(self):
        return self.title

class Application(models.Model):
    job          = models.ForeignKey(Job, on_delete=models.CASCADE)
    applicant    = models.ForeignKey(User, on_delete=models.CASCADE)
    cover_letter = models.TextField()
    date_applied = models.DateTimeField(auto_now_add=True)

    class Meta:
        unique_together = ('job','applicant')
@receiver(post_save, sender=User)
def create_user_profile(sender, instance, created, **kwargs):
    if created:
        UserProfile.objects.create(user=instance)