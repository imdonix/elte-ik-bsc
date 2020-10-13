// TŰRI ERIK - Webprogramozás
// 4. házi feladat mintamegoldása (tehát más megoldás is jó LEHET)

const getAllCookies = () => {
	if (!document.cookie) return new Map();
	return new Map(
		document.cookie.split(";").map((cookie) => {
			return cookie.trim().split("=");
		})
	);
};

const hasCookie = (key) => {
	return getAllCookies().has(key);
};

const getCookie = (key) => {
	return getAllCookies().get(key);
};

const setCookie = (key, value) => {
	const cookies = getAllCookies();
	cookies.set(key, value);
	const newCookies = [];
	for (const [key, value] of cookies.entries())
		newCookies.push(`${key}=${value}`);
	document.cookie = newCookies.join(";");
};
