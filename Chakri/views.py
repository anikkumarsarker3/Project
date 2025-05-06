from django.shortcuts import render, redirect, get_object_or_404
from django.contrib.auth import login, authenticate, logout
from django.contrib.auth.decorators import login_required, user_passes_test
from django.db.models import Q

from .forms import SignUpForm, JobForm, ApplicationForm
from .models import Job, Application

def is_employer(user):
    return user.is_authenticated and user.userprofile.role=='employer'

def is_seeker(user):
    return user.is_authenticated and user.userprofile.role=='seeker'

def signup_view(request):
    if request.method=='POST':
        form = SignUpForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('login')
    else:
        form = SignUpForm()
    return render(request,'signup.html',{'form':form})

def login_view(request):
    if request.method=='POST':
        u = request.POST['username']
        p = request.POST['password']
        user = authenticate(request, username=u, password=p)
        if user:
            login(request,user)
            return redirect('job_list')
    return render(request,'login.html')

def logout_view(request):
    logout(request)
    return redirect('login')

def job_list(request):
    qs = Job.objects.filter(is_active=True)
    q  = request.GET.get('q')
    if q:
        qs = qs.filter(Q(title__icontains=q)|Q(description__icontains=q))
    return render(request,'job_list.html',{'jobs':qs})

def job_detail(request, pk):
    job = get_object_or_404(Job, pk=pk)
    return render(request,'job_detail.html',{'job':job})

@user_passes_test(is_employer)
def job_create(request):
    if request.method=='POST':
        form = JobForm(request.POST)
        if form.is_valid():
            j = form.save(commit=False)
            j.employer = request.user
            j.save()
            return redirect('job_detail', pk=j.pk)
    else:
        form = JobForm()
    return render(request,'job_form.html',{'form':form})

@user_passes_test(is_employer)
def job_edit(request, pk):
    job = get_object_or_404(Job, pk=pk, employer=request.user)
    form = JobForm(request.POST or None, instance=job)
    if form.is_valid():
        form.save()
        return redirect('job_detail', pk=pk)
    return render(request,'job_form.html',{'form':form})

@user_passes_test(is_employer)
def job_delete(request, pk):
    job = get_object_or_404(Job, pk=pk, employer=request.user)
    if request.method=='POST':
        job.delete()
        return redirect('job_list')
    return render(request,'job_confirm_delete.html',{'job':job})

@user_passes_test(is_seeker)
def apply_job(request, pk):
    job = get_object_or_404(Job, pk=pk, is_active=True)
    if request.method=='POST':
        form = ApplicationForm(request.POST)
        if form.is_valid():
            a = form.save(commit=False)
            a.job = job
            a.applicant = request.user
            a.save()
            return redirect('job_detail', pk=pk)
    else:
        form = ApplicationForm()
    return render(request,'apply_form.html',{'form':form,'job':job})
