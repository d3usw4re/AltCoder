int writeAltCode(String message){
	char chars[message.length()+1];
	message.toCharArray(chars, message.length()+1);
	
	for(int a = 0; a<sizeof(chars)-1; a++){
		Keyboard.press(KEY_LEFT_ALT);
		
		int dec_char = (int)chars[a];
		int b = 3;
		int char_ascii[] = {-1, -1, -1, -1};
		while(dec_char > 0) {
			char_ascii[b] = dec_char % 10;
			dec_char /= 10;
			b--;
		}
		for(b=0; b<4; b++){
			if(char_ascii[b] != -1){
				if(char_ascii[b] == 0){
					Keyboard.press(234);
					Keyboard.release(234);
				}else{
					Keyboard.press(224 + char_ascii[b]);
					Keyboard.release(224 + char_ascii[b]);
				}
			}
		}
		Keyboard.release(KEY_LEFT_ALT);
	}
	return 0;
}