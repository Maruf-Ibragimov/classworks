bool getUserPromptString(string prompt, string* input) {
    cout << "Enter " << prompt << ": ";
    cin >> *input;
    return true;
}

bool getUserPromtInt(string prompt , int *input){
    cout<<"Enter "<<prompt<<": ";
    cin>>*input;
    return true;
}

bool getUserPromtDouble(string prompt , double *input){
    cout<<"Enter "<<prompt<<": ";
    cin>>*input;
    return true;
}