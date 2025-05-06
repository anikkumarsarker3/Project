from django import forms
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User

from .models import Job, Application, UserProfile

class SignUpForm(UserCreationForm):
    role = forms.ChoiceField(
        choices=UserProfile.ROLES,
        widget=forms.RadioSelect,
        label="I am a"
    )

    class Meta:
        model = User
        fields = ['username','email','password1','password2','role']

    def save(self, commit=True):
        user = super().save(commit)
        user.userprofile.role = self.cleaned_data['role']
        user.userprofile.save()
        return user

class JobForm(forms.ModelForm):
    class Meta:
        model = Job
        fields = ['title','description','location','salary_range','job_type','is_active']
        widgets = {
            'description': forms.Textarea(attrs={'rows':4}),
        }

class ApplicationForm(forms.ModelForm):
    class Meta:
        model = Application
        fields = ['cover_letter']
        widgets = {
            'cover_letter': forms.Textarea(attrs={'rows':5}),
        }
