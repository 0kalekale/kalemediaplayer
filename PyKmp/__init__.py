import youtube_dl


def get_url(url):
    a = youtube_dl.YoutubeDL().extract_info(url, download=False)

    count = 0

    best_url = ""
    okay_url = ""
    bad_url = ""
    try:
        for i in range(0, len(a['formats'])):
            # print(a['formats'][i]['ext'])
            # print(a['formats'][i]['quality'])

            if a['formats'][i]['quality'] > 4:
                best_url = a['formats'][i]['url']
            elif a['formats'][i]['quality'] > 3:
                okay_url = a['formats'][i]['url']
            else:
                bad_url = a['formats'][i]['url']
    except KeyError:
        return url

    audio_url = ""
    for i in range(0, len(a['formats'])):
        if a['formats'][i]['vcodec'] == 'none':
            audio_url = a['formats'][i]['url']

    if best_url == "" and okay_url != "":
        return okay_url, audio_url
    elif best_url == "" and okay_url == "":
        return bad_url, audio_url
    else:
        return best_url, audio_url
